#!/bin/bash

# Функция проверки доступности пути
check_path() {
 local path="$1"
 if [[ ! -d "$path" ]]; then
  echo "Ошибка: Неверный путь: $path"
  exit 1
 fi
}

