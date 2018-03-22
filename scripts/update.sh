SCRIPT=0 4 1 * * apt-get -y update && apt-get -y upgrade /var/log/update_script.log

crontab -l > crontab_tmp
echo $SCRIPT >> crontab_tmpcontr
