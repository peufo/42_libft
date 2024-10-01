#!/bin/bash

sed -i "" "$(wc -l < Makefile),\$s;.*;# Voici les sources nécessaires à la compilation de mon programme : $@ $;g" Makefile
