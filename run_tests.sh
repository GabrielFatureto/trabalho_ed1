#!/bin/bash

# --- Configurações ---
TED="./src/ted"
SAIDA="svg_txt_resultado"
VALGRIND_FLAGS="-s --leak-check=full --show-leak-kinds=all --track-origins=yes"

# --- Cria a pasta de saída ---
echo "Garantindo que a pasta de saída '$SAIDA' exista..."
mkdir -p $SAIDA
echo ""

# --- 1º Geo ---
echo "Rodando testes do 1º Geo (t-0retg-cres.geo)..."
valgrind $VALGRIND_FLAGS $TED -e t-0retg-cres -f t-0retg-cres.geo -o $SAIDA -q t-0retg-cres/d1-seq-raj.qry
valgrind $VALGRIND_FLAGS $TED -e t-0retg-cres -f t-0retg-cres.geo -o $SAIDA -q t-0retg-cres/dsp-cruz-alt.qry
echo ""

# --- 2º Geo ---
echo "Rodando testes do 2º Geo (t-0retg-decres.geo)..."
valgrind $VALGRIND_FLAGS $TED -e t-0retg-decres -f t-0retg-decres.geo -o $SAIDA -q t-0retg-decres/d1-seq-raj.qry
valgrind $VALGRIND_FLAGS $TED -e t-0retg-decres -f t-0retg-decres.geo -o $SAIDA -q t-0retg-decres/disp-cruz.qry
echo ""

# --- 3º Geo ---
echo "Rodando testes do 3º Geo (t-0rets-circs-cres.geo)..."
valgrind $VALGRIND_FLAGS $TED -e t-0rets-circs-cres -f t-0rets-circs-cres.geo -o $SAIDA -q t-0rets-circs-cres/d1-seq-raj.qry
echo ""

# --- 4º Geo ---
echo "Rodando testes do 4º Geo (t-1retg-cres-2.geo)..."
valgrind $VALGRIND_FLAGS $TED -e t-1retg-cres-2 -f t-1retg-cres-2.geo -o $SAIDA -q t-1retg-cres-2/dspcentro-2.qry
valgrind $VALGRIND_FLAGS $TED -e t-1retg-cres-2 -f t-1retg-cres-2.geo -o $SAIDA -q t-1retg-cres-2/dspcentro-2-chaco.qry
echo ""

# --- 5º Geo ---
echo "Rodando testes do 5º Geo (t-2figs-alet.geo)..."
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-1x1-norte.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-1x1-oeste.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-3x3-lll.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-3x3-nol.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-3x3-norte-longe.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-3x3-norte-prox.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-3x3-oeste-longe.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-3x3-oeste-prox.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-norte-10x7-chaco.qry
valgrind $VALGRIND_FLAGS $TED -e t-2figs-alet -f t-2figs-alet.geo -o $SAIDA -q t-2figs-alet/d2-oeste-10x7-chaco.qry
echo ""

echo "--- FIM DOS TESTES ---"
