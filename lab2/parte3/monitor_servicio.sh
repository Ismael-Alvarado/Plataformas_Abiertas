#!/bin/bash

tiempo=5

registro=/var/log/monitor_sistema.log
echo "TIMESTAMP CPU% MEM% MEM_RSS_KB" >> "$registro"

while true; do
timestamp=$(date "+%F_%T") #fila fecha
cpu_mem_rss=$(ps -e -o 'pid comm %cpu %mem' --sort=pcpu --no-headers | tail -n 5
) #fila datos
echo "$timestamp $cpu_mem_rss" >> "$registro" 
sleep $tiempo 
done

