#!/bin/bash

source users.sh # Импортируем функцию
source processes.sh
source help.sh
source utils.sh

# Проверка аргументов
if [[ $# -eq 0 ]]; then
 echo "Не указаны аргументы. Используйте -h или --help для справки."
 exit 1
fi

# Обработка аргументов
while [[ $# -gt 0 ]]; do
 case "$1" in
  -u|--users)
   users_func "$@"
   shift ;;
  -p|--processes)
   processes_func "$@"
   shift ;;
  -h|--help)
   help_func "$@"
   exit 0 ;;
  -l|--log)
   log_path="$2"
   shift 2
   exec >"$log_path" 2>&1 ;;
  -e|--errors)
   errors_path="$2"
   shift 2
   exec 2>"$errors_path" ;;
  *)
   echo "Неверный аргумент: $1"
   exit 1 ;;
 esac
done

# Выполнение заданного действия
if [[ "$1" == "-u" || "$1" == "--users" ]]; then
 users_func "$@"
elif [[ "$1" == "-p" || "$1" == "--processes" ]]; then
 processes_func "$@"
fi
