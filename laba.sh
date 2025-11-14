#!/bin/bash

filter() {
	local seen=()
	local result=()

	for item in "$@"; do
		local duplicate=0

		for s in "${seen[@]}"; do
			if [[ "$s" == "$item" ]]; then
			duplicate=1
			break
		fi
	done

	if [[ $duplicate -eq 0 ]]; then
		seen+=("$item")
		result+=("$item")
		fi
	done

	printf "%s\n" "${result[@]}"
}

	if [[ $# -lt 1 ]]; then
		echo "$0 строка1 строка2 строка3 ..."
		exit 1
	fi

filter "$@"
