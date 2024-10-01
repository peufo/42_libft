#!/bin/bash

sed -i "" "$(wc -l < Makefile),\$s;.*;# Les sources nécessaires à la compilation de mon programme sont 🥁🥁🥁 : $@ $;g" Makefile
