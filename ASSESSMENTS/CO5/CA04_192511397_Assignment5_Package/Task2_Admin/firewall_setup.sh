#!/usr/bin/env bash
# Ubuntu UFW example: keep SSH open before enabling remotely.
set -euo pipefail
sudo ufw allow OpenSSH
sudo ufw allow 80/tcp
sudo ufw allow 443/tcp
sudo ufw --force enable
sudo ufw status verbose
