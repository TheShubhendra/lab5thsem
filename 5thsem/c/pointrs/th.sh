#!/bin/bash
array=("oblivion" "solarized-light" "solarized-dark" "classic")
for i in {1..10}; do
for theme in "${array[@]}"; do
gsettings set org.gnome.gedit.preferences.editor scheme $theme
gedit &
sleep 0.4
done
done
