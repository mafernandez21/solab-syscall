#!/usr/bin/env bash
set -euo pipefail
# Uso: scripts/setup_vm_ubuntu.sh   (como solab; pide la contraseña de sudo)

# Si ya se ejecuta como root (p. ej. via "sudo bash ..."), no anteponer sudo.
SUDO="sudo"
[[ "${EUID}" -eq 0 ]] && SUDO=""

echo "[INFO] Actualizando índices de paquetes..."
$SUDO apt update

echo "[INFO] Instalando paquetes base..."
$SUDO apt install -y \
  build-essential \
  strace \
  ltrace \
  util-linux \
  iproute2 \
  busybox-static \
  jq

echo "[INFO] Intentando instalar linux-tools (no bloqueante)..."
$SUDO apt install -y linux-tools-common linux-tools-generic || true
$SUDO apt install -y "linux-tools-$(uname -r)" || true

echo "[INFO] Verificaciones rápidas:"
strace -V | head -n 1
ltrace -V | head -n 1
unshare --version | head -n 1

if [[ -f /sys/fs/cgroup/cgroup.controllers ]]; then
  echo "[OK] cgroup v2 detectado."
else
  echo "[WARN] No se detecta cgroup v2 en /sys/fs/cgroup/cgroup.controllers."
fi

echo "[DONE] Setup finalizado."

