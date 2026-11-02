!#/bin/bash

while true
do
	echo "1.Create Address book"
	echo "2.View Address book"
	echo "3.Insert Record"
	echo "4.Delete Record"
	echo "5.Modify Record"
	echo "6.Exit"
	echo "Enter your choice :"
	read ch

	case $ch in
	1)
		touch address.txt
		echo "Address book created"
		;;
	2)
		cat address.txt
		;;
	3)
		echo "Enter name: "
		read name

		echo "Enter phone: "
		read phone

		echo "Enter Address: "
		read address

		echo "$name $phone $address" >> address.txt
		echo "Record Inserted"
		;;
	4)
		echo "Enter name to delete:"
		read name

		grep -v "$name " address.txt > temp.txt
		mv temp.txt address.txt
		echo "Record deleted"
		;;
	5)
		echo "Enter name to modify :"
		read name

		echo "Enter new name: "
		read newName

		echo "Enter new phone: "
		read newPhone

		echo "Enter new address: "
		read newAddress

		grep -v "$name " address.txt > temp.txt
		mv temp.txt address.txt

		echo "$newName $newPhone $newAddress" >> address.txt
		echo "Record modified"
		;;
	6)
		exit
		;;

	*)
		echo "Invalid choice"
		;;
	esac
done

