#!/bin/bash



crontab -l > crontab_tmp
echo "0 0 * * 1 \
	old_tab=\"\`md5sum /etc/crontab.log 2>-\`\" \
	new_tab=\"\`md5sum /etc/crontab | cut -f1 -d\" \" \`\" \
	if [ \"\$old_tab\" != \"\$new_tab\" ]; then \
		mail -s \"Crontab modified\" root <<< \"\`date\`: Crontab has been modified\" \
		echo \$new_tab > /etc/crontab.log \
	;fi"  >> crontab_tmp
cat crontab_tmp
crontab crontab_tmp
rm crontab_tmp
