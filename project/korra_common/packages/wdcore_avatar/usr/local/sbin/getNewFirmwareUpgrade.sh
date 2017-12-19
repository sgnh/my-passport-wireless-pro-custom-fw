#!/bin/bash
#
# getNewFirmwareUpgrade.sh <immediate> <send_alert>
#
# returns:
#  "<name>"
#  "<version>"
#  "<description>"
#  "<linktoimage>"
# -OR-
# "no upgrade"
#
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/system.conf
#. /etc/nas/alert-param.sh

# see share-param.sh
upgrade_link="/tmp/fw_upgrade_link"
#logtag=$(basename $0)
#logger -s -t "$logtag" "begin script: $@"

server_msg="/tmp/dev_fw_upgrade_link"
fw_upgrade="/tmp/fw_upgrade_info"
update_site=`cat /etc/fwupdate.conf`
#model="Avatar"
model="$modelNumber"
current_version=`cat /etc/version`
newFirmwareAvailable="1011"

# clear old files from aborted update attempts
rm -f ${server_msg}

if [ "$1" != "immediate" ]; then
    if [ -f ${fw_upgrade} ]; then
        cat ${fw_upgrade}
    else
        echo "\"no upgrade\""
    fi
    exit 0
fi

[ -f /etc/language.conf ] && language=$(awk '{if ("language" == $1) {print $2}}' /etc/language.conf)

lang_3ltr=""

case "${language}" in
    fr_FR ) lang_3ltr='fra' ;;
    it_IT ) lang_3ltr='ita' ;;
    de_DE ) lang_3ltr='deu' ;;
    es_ES ) lang_3ltr='esn' ;;
    zh_CN ) lang_3ltr='chs' ;;
    zh_TW ) lang_3ltr='cht' ;;
    ja_JP ) lang_3ltr='jpn' ;;
    ko_KR ) lang_3ltr='kor' ;;
    ru_RU ) lang_3ltr='rus' ;;
    pt_BR ) lang_3ltr='por' ;;
    cs_CZ ) lang_3ltr='cze' ;;
    hu_HU ) lang_3ltr='hun' ;;
    nb_NO ) lang_3ltr='nor' ;;
    nl_NL ) lang_3ltr='nld' ;;
    pl_PL ) lang_3ltr='pol' ;;
    sv_SV ) lang_3ltr='swe' ;;
    tr_TR ) lang_3ltr='tur' ;;
        * ) lang_3ltr='eng' ;;
esac

language="${lang_3ltr:-eng}"

echo "language ${language}" > /etc/languageThreeLetterCode.conf

serial_number=""
[ -f "/etc/nas/.product_improvement_opt_in" ] && serial_number="`cat /tmp/HDSerial`"
#serial_number="`getSerialNumber.sh`"

#Modified not to wake HDD
serial_number="`cat /tmp/HDSerial`"

#update_site="http://supportbeta.wdc.com/nas/list.asp"
# set a timeout of 20 seconds maximum for query
update_query="${update_site}?devtype=${model}&devfw=${current_version}&devlang=${language}&devsn=${serial_number}"
curl -4 -m 20 -s "$update_query" > ${server_msg}
#logger -s -t "$logtag" "$update_query"

#echo "<SoftwareUpgrade xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:noNamespaceSchemaLocation=\"WD_NAS_SoftwareUpgrade.xsd\">" > ${server_msg}
#echo "  <Upgrades>" >> ${server_msg}
#echo "      <Upgrade>" >> ${server_msg}
#echo "          <Version>1.00.13</Version>" >> ${server_msg}
#echo "          <Message>http://supportbeta.wdc.com/nas/msg.asp?f=${model}_01_00_13_msg.html&amp;lang=eng</Message>" >> ${server_msg}
#echo "          <Image>http://download.wdc.com/nas/${model}-010013-000-20131201.bin</Image>" >> ${server_msg}
#echo "          <FileSize>116968806</FileSize>" >> ${server_msg}
#echo "          <ReleaseNotes>http://supportbeta.wdc.com/nas/rel.asp?f=${model}_01_00_13_mktg_release_notes.html&amp;lang=eng</ReleaseNotes>" >> ${server_msg}
#echo "      </Upgrade>" >> ${server_msg}
#echo "      <Upgrade>" >> ${server_msg}
#echo "          <Version>1.00.14</Version>" >> ${server_msg}
#echo "          <Message>http://supportbeta.wdc.com/nas/msg.asp?f=${model}_01_00_14_msg.html&amp;lang=eng</Message>" >> ${server_msg}
#echo "          <Image>http://download.wdc.com/nas/${model}-010014-001-20131209.deb</Image>" >> ${server_msg}
#echo "          <FileSize>116968807</FileSize>" >> ${server_msg}
#echo "          <ReleaseNotes>http://supportbeta.wdc.com/nas/rel.asp?f=${model}_01_00_14_mktg_release_notes.html&amp;lang=eng</ReleaseNotes>" >> ${server_msg}
#echo "      </Upgrade>" >> ${server_msg}
#echo "  </Upgrades>" >> ${server_msg}
#echo "</SoftwareUpgrade>" >> ${server_msg}

getXMLeleContentWithHTMLSpecialCharsDecode() {
    local file=$1
    local token=$2

    cat $file  | 
    sed 's/>/>\n/g; s/&quot;/"/g; s/&lt;/</g; s/&gt;/>/g; s/&amp;/\&/g' |
    sed "s/&apos;/'/g;" |
    grep '</' | awk -F'</' -v token="${token}>" 'BEGIN{OFS=" ";} { if ($2 == token) {print $1}}'
}

Message=$(getXMLeleContentWithHTMLSpecialCharsDecode "$server_msg" "Message")
Image=$(getXMLeleContentWithHTMLSpecialCharsDecode "$server_msg" "Image")
Version=$(getXMLeleContentWithHTMLSpecialCharsDecode "$server_msg" "Version")
ReleaseNotes=$(getXMLeleContentWithHTMLSpecialCharsDecode "$server_msg" "ReleaseNotes")
FileSize=$(getXMLeleContentWithHTMLSpecialCharsDecode "$server_msg" "FileSize")

# convert html 'special entities' to a format that the WebUI can handle (ask sean).
Message=$(echo "$Message" | sed 's/&amp;/\&#38;/g')
Image=$(echo "$Image" | sed 's/&amp;/\&#38;/g')
ReleaseNotes=$(echo "$ReleaseNotes" | sed 's/&amp;/\&#38;/g')

#echo "Version=      ${Version[@]}"
#echo "Message=      ${Message[@]}"
#echo "Image=        ${Image[@]}"
#echo "ReleaseNotes= ${ReleaseNotes[@]}"
#echo "FileSize=     ${FileSize[@]}"

echo "${FileSize[@]}" > /tmp/fw_upgrade_filesize

if [ "$Version" == "" ]; then 
    isUpgrade='false'
else
    isUpgrade='true'
fi
if [ "$Message" == "" ]; then 
    isMessage='false'
else
    isMessage='true'
fi

echo $Version > /tmp/fw_upgrade_version

#echo "isMessage = $isMessage"
#echo "isUpgrade = $isUpgrade"

# first check that server_msg file exists and is not empty
if [ -s ${server_msg} ]; then
    if [ "${isUpgrade}" == 'false' ]; then
        echo "\"no upgrade\"" | tee ${fw_upgrade}
        clearAlerts.sh ${newFirmwareAvailable}
        rm -f /etc/.fw_upgrade_alert
        rm -f /etc/.fw_update_alert
    else
		
        if [ "${isMessage}" == "true" ]; then
            if [ ! -f /etc/.fw_upgrade_alert ]; then
            	sendAlert.sh "${newFirmwareAvailable}"
                touch /etc/.fw_upgrade_alert
                touch /etc/.fw_update_alert
            fi
        elif [ ! -f /etc/.fw_update_alert ]; then
        	sendAlert.sh "${newFirmwareAvailable}"
            touch /etc/.fw_update_alert
        fi

        # first package
        echo "${model}" | tee ${fw_upgrade}
        echo ${Version[0]} | tee -a ${fw_upgrade}
        echo "${model} core firmware" | tee -a ${fw_upgrade}
        echo ${Image[0]} | tee -a ${fw_upgrade}
        #echo ""
        echo ${Message[0]} | tee -a ${fw_upgrade}
        echo ${ReleaseNotes[0]} | tee -a ${fw_upgrade}
        echo ${FileSize[0]} | tee -a ${fw_upgrade}
    
        # second package
        if [ "${Version[1]}" != "" ]; then
            echo "${model}" | tee -a ${fw_upgrade}
            echo ${Version[1]} | tee -a ${fw_upgrade}
            echo "${model} core firmware" | tee -a ${fw_upgrade}
            echo ${Image[1]} | tee -a ${fw_upgrade}
            #echo ""
            echo ${Message[1]} | tee -a ${fw_upgrade}
            echo ${ReleaseNotes[1]} | tee -a ${fw_upgrade}
            echo ${FileSize[1]} | tee -a ${fw_upgrade}
        fi

        # storing the update image link to "$upgrade_link" ENABLES auto-update
        # - do this only if there is no message..
        if [ "${isMessage}" == "false" ]; then
            echo "${Image}" > ${upgrade_link}
        else
            # disable auto update
            rm -f ${upgrade_link}
        fi
    fi
else
    echo "\"error\"" | tee ${fw_upgrade}
    # disable auto-update
    rm -f ${upgrade_link}
fi
