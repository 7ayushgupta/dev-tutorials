rm -f students_info.dat
echo "Started Data Scraping"
function scrape_and_clean() {
    roll=$1
    payload="typ=stud&bk=&numtxt=${roll}"
    curl 'https://oa.cc.iitk.ac.in/Oa/Jsp/OAServices/IITk_SrchRes_new.jsp?sbm=Y' -H 'Host: oa.cc.iitk.ac.in' -H 'User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:58.0) Gecko/20100101 Firefox/58.0' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: https://oa.cc.iitk.ac.in/Oa/Jsp/OAServices/IITk_SrchRes_new.jsp' -H 'Content-Type: application/x-www-form-urlencoded' -H '<Add your own cookie information here, using any cookie extension>' -H 'Connection: keep-alive' -H 'Upgrade-Insecure-Requests: 1' -H 'Cache-Control: max-age=0' --data ${payload} >> ${roll}.txt
    file=${roll}.txt

    rollno=$(cat $file | grep -iPA1 "<b>Roll no: </b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    name=$(cat $file | grep -iPA1 "<b>Name: </b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    program=$(cat $file | grep -iPA1 "<b>Program: </b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    dept=$(cat $file | grep -iPA1 "<b>Department: </b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    hostel=$(cat $file | grep -iPA1 "<b>Hostel Info: </b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    username=$(cat $file | grep -iPo "mailto:[a-zA-z]+@iitk.ac.in" | cut -d ":" -f2 | cut -d "@" -f1)
    hostel=$(cat $file | grep -iPA1 "<b>Hostel Info: </b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    bloodg=$(cat $file | grep -iPA1 "<b> Blood Group:</b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    country=$(cat $file | grep -iPA1 "<b> CountryOfOrigin:</b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    gender=$(cat $file | grep -iPA1 "<b> Gender:</b>" | sed "s/[[:space:]]\+/ /g" | tail -n 1)
    output="$rollno | $name | $program | $dept | $hostel | $username | $gender | $bloodg | $country"
    echo $output >> students_info.dat
    rm -f $file
}
echo "Scraping Data for Y17"
for roll in {170001..170830}
do
    scrape_and_clean ${roll}
done
echo "Scraping Data for Y16"
for roll in {160001..160832}
do
    scrape_and_clean ${roll}
done
echo "Scraping Data for Y15"
for roll in {150001..150845}
do
    scrape_and_clean ${roll}
done
echo "Scraping Data for Y14"
for roll in {14001..14832}
do
    scrape_and_clean ${roll}
done
echo "Scraping Data for Y13"
for roll in{13001..13819}
do
    scrape_and_clean ${roll}
done
echo "Scraping Data for Y12"
for roll in {12001..12837}
do
    scrape_and_clean ${roll}
done
echo "Scraping Data for Y11"
for roll in {11001..11833}
do
    scrape_and_clean ${roll}
done
echo "Scraping Completed. Now you may start the Student Search"
