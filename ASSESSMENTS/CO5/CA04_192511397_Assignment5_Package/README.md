# Operating Systems – Assignment 5 (CO5)
**Student:** H SARAVANA  
**Register Number:** 192511397  
**Topic:** Linux, Containers and Virtualisation for Efficient Operations

> Evidence note: screenshots and sample outputs in the report/package are illustrative placeholders. Replace them with screenshots and measurements from your own Linux/WSL, Docker and Kubernetes environment before submission.

## Quick start (Ubuntu/WSL)
```bash
sudo apt update
sudo apt install -y python3 python3-venv python3-pip docker.io curl nginx
sudo systemctl enable --now docker
```
For Docker Desktop, install it on Windows and enable WSL integration for your Ubuntu distribution.

## Build and run portal
```bash
cd Task4_Docker
docker build -t result-portal:1.0 .
docker run --rm -p 8000:8000 result-portal:1.0
```
Open http://localhost:8000

## Compose
```bash
docker compose up --build -d
docker compose ps
docker compose down
```

## Kubernetes (Minikube)
```bash
minikube start
kubectl apply -f Task5_Cloud/deployment.yaml
kubectl apply -f Task5_Cloud/service.yaml
kubectl get pods -w
kubectl get svc
kubectl delete pod <pod-name>
kubectl get pods -w
```
Use the HPA only after Metrics Server is available; see Task5_Cloud/hpa.yaml.

## Google Cloud image registry (Artifact Registry)
GCR's legacy registry is replaced for new projects by Artifact Registry. Commands are in `Task5_Cloud/google_registry.md`.

## Evidence checklist
See `Screenshots/evidence_checklist.md`. Capture your own terminal/browser screenshots and add them to the folder before submitting.
