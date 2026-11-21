#!/usr/bin/env bash
# Simple repeatable measurement helpers; run separately for each deployment.
set -euo pipefail
URL="${1:-http://127.0.0.1:8000/}"
COUNT="${2:-20}"
echo "URL=$URL requests=$COUNT"
for i in $(seq 1 "$COUNT"); do
  curl -s -o /dev/null -w "%{http_code} %{time_total}\n" "$URL"
done
