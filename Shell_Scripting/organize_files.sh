for file in *.sh;
do
	mv "$file" shelldir
done
for file in *.jpeg
do
	mv "$file" jpgdir
done
for file in *.c
do
	mv "$file" cdir
done
