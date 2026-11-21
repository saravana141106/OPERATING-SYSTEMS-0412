FROM python:3.12-slim
WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt     && useradd --create-home --uid 10001 portal
COPY app.py ./app.py
COPY templates ./templates
USER portal
EXPOSE 8000
HEALTHCHECK --interval=30s --timeout=3s --start-period=5s --retries=3 CMD python -c "import urllib.request; urllib.request.urlopen('http://127.0.0.1:8000/health',timeout=2)"
CMD ["gunicorn","--bind","0.0.0.0:8000","--workers","2","app:app"]
