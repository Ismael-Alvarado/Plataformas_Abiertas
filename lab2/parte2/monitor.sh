#!/bin/bash

arg_num=$#
# COmprobar uso correcto con numero de argumentos
if [ $arg_num -ne 2 ]; then
	echo "Modo de uso:"
	echo "$0 <comando en comillas> <intervalo en segundos>"
	exit 
fi

comando=$1
tiempo=$2

#ejecutar en background
$comando &
trap abortar SIGINT #capturar el ctrl C
#jobs -l | awk '{print $2}' | xargs echo
#jobs -l otro approach que estaba haciendo
pid=$! #pid del proceso inicializado
abortar() { #funcion para cerrar con trap
graficar
kill -SIGTERM $pid
echo "Proceso finalizado..."

exit
}
graficar() { #funcion de graficar
# cracion archivo temporal mas amigable con gnuplot
data_tmp="data_$pid.dat"
awk -v intervalo="$tiempo" '
NR==1 {next}  # por encabezado
{
    tiempo = (NR-1) * intervalo #como el intervalo es en segundo se normaliza con cantidad de filas #abria error si lo colocan en minutos
    print tiempo, $2, $4
}
' "$registro" > "$data_tmp"

gnuplot <<EOF
set terminal png size 800,600
set output "monitor_${pid}.png"

set title "Monitoreo (PID $pid)"
set xlabel "Tiempo (s)"

set ylabel "CPU (%)"
set y2label "Memoria RSS (KB)"

set y2tics
set grid

plot "$data_tmp" using 1:2 with lines title "CPU (%)", \
     "$data_tmp" using 1:3 axes x1y2 with lines title "RSS (KB)"
EOF
rm "$data_tmp"
}
registro="monitor_$pid.log" #crear el log
echo "TIMESTAMP CPU% MEM% MEM_RSS_KB" > "$registro"
timestamp=$(date "+%F_%T") #fila fecha
cpu_mem_rss=$(ps -p $pid -o '%cpu %mem rss' --no-headers) #fila datos

while [ -n "$cpu_mem_rss" ]; do
echo "$timestamp $cpu_mem_rss" >> "$registro"
sleep $tiempo 
timestamp=$(date "+%F_%T") 
cpu_mem_rss=$(ps -p $pid -o '%cpu %mem rss' --no-headers)
done
#graficar
graficar
