data="students_info.dat"
echo "Welcome to Student Search"


rollno=; name=; program=; dept=; host=; username=; gender=; bloodg=; country=;
while getopts r:n:p:h:u:g:b:c: option
do
case "$option"
in
r)  rollno="$OPTARG";;
n)  name="$OPTARG";;
p)  prog="$OPTARG";;
d)  dept="$OPTARG";;
h)  hostel="$OPTARG";;
u)  username="$OPTARG";;
g)  if [ "$OPTARG" == "M" ] || [ "$OPTARG" == "m" ]; then
      gender="M"
    elif [ "$OPTARG" == "F" ] || [ "$OPTARG" == "f" ]; then
      gender="F"
    else
      printf "Enter valid gender (M or F)"
      exit 1
    fi;;
b)  if [ "$OPTARG" == "A+" ] || [ "$OPTARG" == "a+" ]; then
      bloodg="A+"
    elif [ "$OPTARG" == "B+" ] || [ "$OPTARG" == "b+" ]; then
      bloodg="B+"
    elif [ "$OPTARG" == "AB+" ] || [ "$OPTARG" == "ab+" ]; then
      bloodg="AB+"
    elif [ "$OPTARG" == "O+" ] || [ "$OPTARG" == "o+" ]; then
      bloodg="O+"
    elif [ "$OPTARG" == "A-" ] || [ "$OPTARG" == "a-" ]; then
      bloodg="A-"
    elif [ "$OPTARG" == "B-" ] || [ "$OPTARG" == "b-" ]; then
      bloodg=="B-"
    elif [ "$OPTARG" == "AB-" ] || [ "$OPTARG" == "ab-" ]; then
      bloodg=="AB-"
    elif [ "$OPTARG" == "O-" ] || [ "$OPTARG" == "o-" ]; then
      bloodg=="O-"
    else
      printf "Enter valid blood group (A+ or AB+)"
      exit 1
    fi;;
?)  printf "Unknown flag %s \n" $option;;
esac
done

echo "ROLL NO. | NAME | PROGRAM | DEPARTMENT | HOSTEL INFO | USERNAME | GENDER | BLOOD GROUP | COUNTRY" >| temp.txt
echo "======== | ========================= | ======= | ========================= | ============= | ======== | ====== " >> temp.txt
grep -irhP "[^\|]*$rollno[^\|]* \|[^\|]*$name[^\|]* \|[^\|]*$program[^\|]* \|[^\|]*$dept[^\|]* \|[^\|]*$host[^\|]* \|[^\|]*$username[^\|]* \| $gender" ${data} 
