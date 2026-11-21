#!/usr/bin/env bash
# Example user/group setup. Review names before running on a real system.
set -euo pipefail
sudo groupadd -f portaladmins
sudo useradd -m -s /bin/bash portalops 2>/dev/null || true
sudo usermod -aG portaladmins portalops
sudo install -d -o root -g portaladmins -m 0750 /srv/result-portal
echo "Created/checked portalops and portaladmins; /srv/result-portal permissions set."
