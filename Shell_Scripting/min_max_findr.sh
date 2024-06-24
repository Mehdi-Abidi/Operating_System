read -p "Enter Number 1: " number
min=$number
max=$number
for(( i=2; i<=5;i++ ));do
	read -p "Enter Number $i: " n
	if [ "$n" -lt "$min" ]; then
		min=$n
	elif [ "$n" -gt "$max" ]; then
		max=$n
	else
		continue
	fi
done
echo "The Max Element is: $max "
echo "The Min Element is: $min "
