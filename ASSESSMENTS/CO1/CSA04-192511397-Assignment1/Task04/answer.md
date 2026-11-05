# Task 4 – Operating-System Services

| Service | Monitors | Tablets | Workstations | Database | MRI server |
|---|---|---|---|---|---|
| User interface | Minimal/local status | Touch UI | Full GUI | Admin console only | Operator console |
| Program execution | Fixed validated tasks | Clinical apps | Clinical apps | DB engine/services | Imaging pipeline |
| I/O operations | Sensor, alarm, display | Touch, Wi-Fi, camera | Keyboard, display, network | Storage/network | Scanner/storage/GPU |
| File system | Small configuration/log area | Encrypted app storage | Encrypted user files | Journals, data, backups | Large image datasets |
| Communication | Device gateway | Secure hospital network | Secure network | Replication/API | Scanner and archive |
| Error detection | Watchdog, sensor plausibility | App/device health | System/application logs | Checksums, monitoring | Job and device monitoring |
| Resource allocation | Fixed priorities | Power-aware scheduling | Fair scheduling | DB-aware CPU/memory/I/O | Parallel scheduling |
| Accounting | Event/audit logs | Device usage | User audit | Full transaction audit | Job/resource logs |
| Protection/security | Secure boot, least privilege | Encryption, MDM, MFA | MFA, endpoint controls | RBAC, encryption, audit | Role controls, network segmentation |

For a monitor, omit a full desktop GUI, general-purpose user accounts, unnecessary background services and nonessential packages. Retain validated sensor I/O, alarm logic, watchdog, secure update, event logging and network authentication.

The database requires durable file/storage services, transaction recovery, access control, encryption, audit logging, backups, replication and resource management. Patient records must be protected using process isolation, user authentication, role-based authorization, least privilege, encryption in transit/at rest, and audit trails. A process must not be able to read another patient's records merely because it runs on the same host.

## Alternative: full desktop OS on tablets
A desktop OS with every service enabled increases installed storage, RAM use, background CPU activity and startup work. It can also keep radios and background tasks active, reducing battery endurance. A managed mobile OS with only required clinical apps, encryption, remote wipe, and controlled synchronization is more appropriate.
