# smierx Keymap – Änderungsprotokoll

## 2026-05-31

### Bug-Fixes

- **`layer_state_set_user` hinzugefügt** – Raw HID Report wird jetzt bei jedem Layer-Wechsel gesendet (`byte[0]=0x4C`, `byte[1]=layer_index`). Ohne diese Funktion hat der QMK Overlayer keinen Layer-Wechsel empfangen.
- **Layer 14 Syntax-Fehler behoben** – `[14]  LAYOUT(` → `[14] = LAYOUT(` (fehlendes `=`).
- **`layer_off(30)` entfernt** – Im `PW_1`-Macro wurde Layer 30 deaktiviert, der nicht existiert.
- **`TD_EQ_PLUS` korrigiert** – War `ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_EQL)` (doppelt), jetzt `ACTION_TAP_DANCE_DOUBLE(KC_EQL, DE_PLUS)`.

---

## 2026-06-04

### Layer 17 – Unicode Griechisch + Mathematik

Neuer TG()-Layer mit 23 griechischen Buchstaben (phonetisch auf Colemak-DH) und 16 mathematischen Operatoren/Relationen. Aktivierung via TG(17) auf Layer 12 (Q-Position).

- **Griechisch** (Shift = Großbuchstabe): α β γ δ ε ζ η θ ι κ λ μ ν ξ π ρ σ τ υ φ χ ψ ω
- **Operatoren** (Row 1 links): → ← ⇒ ⇔
- **Relationen** (Row 1 rechts): ≤ ≥ ≠ ≈ ∈
- **Analyse** (Row 2 rechts): ∑ ∫
- **Geometrie** (Row 4 rechts): ∞ ∇ ⊂ ⊃ (und ∂ links)

Unicode-Eingabe via `UNICODEMAP_ENABLE` + WinCompose (Windows) / nativ (macOS). Umschalten mit `UC_NEXT` (Layer 12, Q-Position).

### Layer 18 – LaTeX-Makros

Spiegelidentisches Layout zu Layer 17, sendet statt Unicode-Zeichen LaTeX-Befehle per `SEND_STRING`:
`\alpha`, `\leq`, `\sum`, `\nabla` usw. Aktivierung via TG(18) auf Layer 12 (W-Position).

### Layer 12 – Selector-Update

Row 2 links: UC_NEXT (Q), TG(17) (W), TG(18) (F) hinzugefügt.

### config.h erstellt

`UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_MACOS` – UC_NEXT schaltet zwischen beiden Modi um.

---

## 2026-06-03

### Layer 16 – Mac-Overlay hinzugefügt

TG()-Overlay (aktivierbar auf Layer 12, letzte Pos. rechts Row 4): überschreibt nur die 4 Windows-Ctrl-Shortcuts in Layer 1 mit macOS-Cmd/Option-Äquivalenten.

---

## 2026-05-31

### Layer 1 – Navigation (Redesign)

Layer 1 wird via `LT(1, ENT)` (linker Daumen) aktiviert.

#### Vorher

Nur 4 Pfeiltasten auf der rechten Home-Row (via CK_19–CK_21 + KC_UP), alles andere KC_NO.

#### Nachher

| Row | Linke Hand | Rechte Hand |
|-----|-----------|-------------|
| 1 | – (KC_NO) | – (KC_NO) |
| 2 | Esc · Undo · Redo · Tab | Home · PgUp · PgDn · End |
| 3 | **TRNS** (HRM-Mods) | ← · ↓ · ↑ · → |
| 4 | – (KC_NO) | Wort← · – · – · Wort→ |
| Thumbs | TRNS | TRNS |

**Keycodes im Detail:**

- Row 2 links: `KC_ESC`, `LCTL(KC_Z)`, `LCTL(LSFT(KC_Z))`, `KC_TAB`
- Row 2 rechts: `KC_HOME`, `KC_PGUP`, `KC_PGDN`, `KC_END`
- Row 3 links: `_______` × 4 → HRM-Modifier (⇧/A, ⌥/R, ⌘/S, ⌃/T) fallen durch
- Row 3 rechts: `KC_LEFT`, `KC_DOWN`, `KC_UP`, `KC_RGHT`
- Row 4 rechts: `LCTL(KC_LEFT)`, `LCTL(KC_RGHT)` (Wort-Navigation, Windows)
- Alle Thumb-Keys: `_______` (DEL, SPC, BSPC bleiben erreichbar)

#### Warum TRNS auf der linken Home-Row

Die HRM-Modifier auf A/R/S/T sind im Base-Layer als `MT()`-Keys definiert. Mit `_______` in Layer 1 fallen sie durch → man kann kombinieren:

| Kombination | Effekt |
|------------|--------|
| ⇧ + ← / → | Zeichen-Selektion (alle OS) |
| ⌃ + ← / → | Wort-Sprung (Windows) |
| ⌥ + ← / → | Wort-Sprung (macOS) |
| ⌘ + ← / → | Zeilenanfang/-ende (macOS) |
| ⌃⇧ + ← / → | Wort-Selektion (Windows) |
| ⌥⇧ + ← / → | Wort-Selektion (macOS) |

Die expliziten `LCTL()`-Keycodes in Row 4 sind Windows-Boni für schnellen Zugriff ohne Modifier-Kombination.
