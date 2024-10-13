#!/bin/bash

processes_func() {
 # Вывод списка запущенных процессов
 echo "Запущенные процессы:"
 ps aux | awk '{print $2 " - " $11}' | sort -n
}
