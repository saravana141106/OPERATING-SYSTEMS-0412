# Google Container Registry / Artifact Registry

Google Container Registry (GCR) is the legacy container registry. For new setups, Google Cloud recommends Artifact Registry.

## Create a repository (replace REGION and PROJECT_ID)
```bash
gcloud config set project PROJECT_ID
gcloud services enable artifactregistry.googleapis.com
gcloud artifacts repositories create result-portal   --repository-format=docker --location=REGION   --description="Assignment 5 portal images"
gcloud auth configure-docker REGION-docker.pkg.dev
```

## Build, tag and push
Run from the Task4_Docker directory:
```bash
docker build -t result-portal:1.0 .
docker tag result-portal:1.0 REGION-docker.pkg.dev/PROJECT_ID/result-portal/result-portal:1.0
docker push REGION-docker.pkg.dev/PROJECT_ID/result-portal/result-portal:1.0
```

## Verify
```bash
gcloud artifacts docker images list REGION-docker.pkg.dev/PROJECT_ID/result-portal
```
Use your real Google Cloud project ID and region. Billing may be required; review quotas, pricing and permissions before creating resources. Do not publish credentials, service-account keys or secrets in GitHub.
