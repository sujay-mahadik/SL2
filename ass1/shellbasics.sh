#!/bin/bash
#1
#shell basics
#sujay sanjay mahadik

echo "Enter filename"
read data
temp=temp.db
if [ -f $data ]
	then 
	echo "File already exits!!!!!"
else
	Roll_no='Roll_no'
	Name='Name'
	Dept='Dept'
	City='City'
	printf '%-10s %-10s %-10s %-10s %-10s\n' $Roll_no $Name $Dept $City >> $data 
	echo "......................................"  >> $data
	echo "File successfully created!!!"

fi

function insert()
{

	echo "Enter Name:"
	read name
	echo "Enter Department:"
	read dept
	echo "Enter City:"
	read city
	printf '%-10s %-10s %-10s %-10s %-10s\n' $1 $name $dept $city >> $data
	echo "Record has been Inserted..."
	return
}

delete ()				   
{
	grep -v -w $1 $data > $temp
	echo "Record has been deleted..."
	cat $temp > $data
	return
}

modify()				     
{
	grep -v -w $1 $data > $temp
	echo "Enter the Name : "
	read name
	echo "Enter the Department : "
	read dept
	echo "Enter the City"
	read city
	printf '%-10s %-10s %-10s %-10s %-10s\n' $1 $name $dept $city >> $temp
	echo "Record has been Modified..."
	cat $temp > $data
	return
}

for((;;))
do
	echo "."
	echo "."
	echo "MENU"
	echo "......................................"
	echo "1.Insert new record"
	echo "2.Display file"
	echo "3.Delete record"
	echo "4.Modify record"
	echo "5.Exit"
	echo "Enter your choice"
	echo "."
	echo "."
	read ch
	case $ch in

		1)
while [ true ]
do
	echo "."
	echo "."
	echo "Insert New Record"
	echo "......................................"
	echo "Enter Roll No. : "
	read roll

	if (grep -w $roll $data)   
		then
		echo "Roll no already exists..."
	else
		insert $roll
		break
	fi
done
;;

2)   
echo "Contents "
echo "......................................"
cat $data
echo "......................................"
;;

3)
echo "Delete Record"
echo "......................................"
echo "Enter roll no to be deleted"
read roll
if(grep -w $roll $data)
	then 
	delete $roll
else
	echo "No such Record..." 
fi
;;

4)     
echo "Modify Record"
echo "......................................"
echo "Enter Roll No to be modified : "
read roll

if (grep -w $roll $data)   
	then
	modify $roll
else
	echo "Roll_no not present"
fi
;;
5)
echo "......................................"
echo "okay bye"
exit
;;
*)
echo "Invalid Choice..."
;;

esac
done





















