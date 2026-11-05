# Task 12 – Re-evaluate and Adapt the Design

## A. Impact analysis
Home monitoring adds untrusted internet connections, variable network delay, intermittent connectivity, device provisioning and remote-update risks. Cloud records add distributed storage, identity federation, data residency, service-level agreements, backup and shared-responsibility security requirements. The RTOS monitor design remains appropriate locally, but communications and backend architecture must expand.

## B. Evaluation of original design
The original design can support the change only if it does not depend on a continuous internet connection for immediate alarms. Home devices must detect urgent conditions locally and provide local alerts; cloud delivery is for clinician notification, trends and record synchronization. A cloud-only alarm path would have unpredictable network delay and cannot guarantee a 10 ms deadline. The clustered database remains useful, but must be extended with secure cloud replication and conflict handling.

## C. Adapted design
Retain the hospital architecture and modify it:
- Use an embedded RTOS on home monitoring devices with local threshold detection, secure boot and encrypted store-and-forward.
- Use a mobile gateway/app where needed, with device identity and authenticated pairing.
- Send readings through mutually authenticated TLS connections to an API gateway.
- Use a distributed cloud records service with encryption, role-based access, audit logs, backups, replication and regional recovery.
- Use event timestamps, patient/device identity, sequence numbers and idempotent ingestion to detect duplicates and out-of-order messages.
- Queue readings during network outages and synchronize when connectivity returns.
- Keep bedside alarm decisions local; cloud and WAN are not part of the hard real-time control loop.

## D. Evidence-based defence
This is a RETAIN → MODIFY decision. The monitor's local real-time design is retained because network latency is not bounded. The database and partner-hospital design is modified to a hybrid distributed architecture because remote access and cloud scale are required. The trade-off is greater complexity, cloud/network dependency for remote viewing, and the need for strong identity, privacy and synchronization controls. Local alarms and hospital-level failover preserve essential safety functions during outages.
