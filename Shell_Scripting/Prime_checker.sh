read -p "Enter a Number: " number
c=0
if [ "$number" -lt 2 ];
then
	echo "$number isn't a Prime Number. "
	exit
else

for(( i = 2 ; i < number ; i++ ))
do
	if [ "$((number % i))" -eq 0 ];
	then
		c=1;
	break
	fi
done
fi
if [ "$c" = 0 ];
then
	echo "$number is a Prime Number. "
else
	echo "$number isn't a Prime Number. "
fi
