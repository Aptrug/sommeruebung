#!/bin/sh
id -Gn $FT_USER | awk '{gsub(/ /, ","); printf "%s", $0}'
