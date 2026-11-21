#!/usr/bin/env bash
# Basic system snapshot for Assignment 5
set -euo pipefail
echo "===== SYSTEM ====="
hostname
date
uptime
echo "===== CPU / PROCESSES ====="
ps -eo pid,comm,%cpu,%mem --sort=-%cpu | head -n 8
echo "===== MEMORY ====="
free -h
echo "===== DISK ====="
df -h /
echo "===== NETWORK ====="
ip -brief address || true
echo "===== LISTENING PORTS ====="
ss -tuln | head -n 12
