#!/usr/bin/env python3

import os
import argparse
from reportlab.lib.pagesizes import A4, landscape
from reportlab.pdfgen import canvas
from PIL import Image as PILImage


def parse_args():
    parser = argparse.ArgumentParser(
        description="Distribui imagens em páginas A4 (6 por página)"
    )

    parser.add_argument(
        "-i", "--input",
        required=True,
        help="Pasta contendo as imagens"
    )

    parser.add_argument(
        "-o", "--output",
        required=True,
        help="Arquivo PDF de saída (ex: ./out/saida.pdf)"
    )

    return parser.parse_args()


def main():
    args = parse_args()

    input_dir = args.input
    output_file = args.output

    if not os.path.isdir(input_dir):
        raise SystemExit(f"Pasta de entrada não encontrada: {input_dir}")

    # cria diretório do output automaticamente
    out_dir = os.path.dirname(os.path.abspath(output_file))
    os.makedirs(out_dir, exist_ok=True)

    files = sorted([
        os.path.join(input_dir, f)
        for f in os.listdir(input_dir)
        if f.lower().endswith((".png", ".jpg", ".jpeg"))
    ])

    if not files:
        raise SystemExit("Nenhuma imagem encontrada.")

    cols, rows = 3, 2
    imgs_per_page = 6

    page_w, page_h = landscape(A4)
    cell_w = page_w / cols
    cell_h = page_h / rows

    c = canvas.Canvas(output_file, pagesize=landscape(A4))

    print(f"{len(files)} imagens encontradas")

    for i, path in enumerate(files):

        pos = i % imgs_per_page
        col = pos % cols
        row = pos // cols

        x = col * cell_w
        y = page_h - ((row + 1) * cell_h)

        img = PILImage.open(path)
        iw, ih = img.size

        ratio = min(cell_w / iw, cell_h / ih)
        w = iw * ratio
        h = ih * ratio

        cx = x + (cell_w - w) / 2
        cy = y + (cell_h - h) / 2

        c.drawImage(path, cx, cy, width=w, height=h)

        if pos == imgs_per_page - 1:
            c.showPage()

    c.save()

    print("PDF gerado:", output_file)


if __name__ == "__main__":
    main()
