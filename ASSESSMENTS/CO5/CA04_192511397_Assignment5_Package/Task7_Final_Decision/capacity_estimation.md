# Capacity estimate for 150,000 result-day students
The assignment specifies 150,000 students over two hours. Average arrival rate is:
150,000 / 7,200 seconds = 20.83 requests/second if each student makes one request uniformly.
Result-day traffic is not uniform, so plan a peak factor (illustrative 5x–10x) and test with load generation. At 5x, target roughly 104 requests/second; at 10x, roughly 208 requests/second. This is a planning estimate, not a measured benchmark.

## Recommended architecture
- Public load balancer / reverse proxy with TLS.
- Stateless portal containers replicated across nodes.
- Managed database or replicated database with backups; keep database outside disposable containers and persist data.
- Kubernetes autoscaling, readiness checks, resource requests/limits, and monitoring.
- Hybrid approach: university-owned infrastructure for baseline workloads and sensitive data, cloud capacity for result-day burst, subject to budget and policy review.

Do not claim this estimate proves capacity. Measure throughput, latency percentiles, error rate, CPU/memory and recovery under a representative load test.
