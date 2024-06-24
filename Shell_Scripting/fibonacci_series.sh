read -p "Enter the Number Of Terms: " n
a=0
b=1
echo "FIBONACCI SERIES: "
echo "$a "
for (( i=1 ; i<n; i++ ))
do
	echo "$b "
	c=$((a+b))
	a=$b
	b=$c
done
