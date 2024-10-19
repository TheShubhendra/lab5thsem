for i in 0 0.1 0.2 0.3 0.4  0.5 1 2 5 10 50 1000 1000 1;
do
  sleep 0.2
  xrandr --output HDMI-1 --brightness $i
done
