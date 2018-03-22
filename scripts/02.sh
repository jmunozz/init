sudo crontab -l > crontab_tmp
echo "0 4 * * mon apt-get -y update >> /var/log/update_script.log && apt-get -y upgrade >> /var/log/update_script.log" >> crontab_tmp
cat crontab_tmp
sudo crontab crontab_tmp
sudo rm crontab_tmp
