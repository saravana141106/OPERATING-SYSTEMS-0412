from flask import Flask, render_template, jsonify
import os, time
app = Flask(__name__)
STARTED = time.time()

@app.get("/")
def home():
    return render_template("index.html", uptime=int(time.time()-STARTED), hostname=os.getenv("HOSTNAME","container"))

@app.get("/health")
def health():
    return jsonify(status="healthy", service="result-portal", uptime_seconds=int(time.time()-STARTED)), 200

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
