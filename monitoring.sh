#!/bin/bash

arch=$(uname -a)

pCPU=$(nproc)
vCPU=$(cat /proc/cpuinfo | grep processor | wc -l)

usedMem=$(free -m | grep Mem: | awk '{print $3}')
totalMem=$(free -m | grep Mem: | awk '{print $2}')
percentMem=$(free -m | grep Mem: | awk '{printf("%.2f"), $3/$2*100}')

diskUsage=$(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)", $3,$2,$5}')

CPULoad=$(mpstat -u | awk '$2 == "all" {print 100-$12}')

lastBoot=$(who -b | awk '{print $3" "$4" "$5}')

LVMUse=$(lsblk | grep lvm | awk '{if ($1) {print "yes"; exit;} else {print "no"; exit;}}')

connexionsTCP=$(cat /proc/net/sockstat | grep TCP | awk '{print $3}')

userLog=$(who | wc -l)

IPv4Adress=$(hostname -I)
MACAdress=$(ip a | grep link/ether | awk '{print $2}')

sudoCount=$(grep sudo /var/log/auth.log | grep COMMAND= | wc -l)

wall " #Architecture: $arch
 #CPU physical : $pCPU
 #vCPU : $vCPU
 #Memory Usage: $usedMem/$totalMem ($percentMem%)
 #Disk Usage: $diskUsage
 #CPU load: $CPULoad%
 #Last boot: $lastBoot
 #LVM use: $LVMUse
 #Connexions TCP : $connexionsTCP ESTABLISHED
 #User log: $userLog
 #Network: IP $IPv4Adress ($MACAdress)
 #Sudo : $sudoCount cmd"
