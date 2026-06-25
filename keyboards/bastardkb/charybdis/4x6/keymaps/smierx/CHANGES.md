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

---

## 2026-06-17

### Layer-Renumerierung (9/10/11 entfernt)

Die leeren Layer 9, 10 und 11 wurden gelöscht, alle darüberliegenden rücken auf:

| Alt | Neu | Layer |
|-----|-----|-------|
| 12 | 9 | Selector |
| 13 | 10 | Media |
| 14 | 11 | F-Tasten |
| 15 | 12 | Maus (`MO`) |
| 16 | 13 | Mac-Overlay (`TG`) |
| 17 | 14 | Unicode (`TG`) |
| 18 | 15 | LaTeX (`TG`) |

Höchster Layer ist jetzt 15 → `LAYER_STATE_32BIT` aus `config.h` entfernt (nicht mehr nötig). Alle `TO()/TG()/MO()`-Referenzen im Selector und in den Defines (`CK_17 = MO(12)`) sowie der Base-Zugang (`TO(9)`) wurden mitgezogen.

### Bug-Fixes

- **Layer 14 & 15 (Unicode/LaTeX) hatten keinen Ausgang** – beide Layer sind fast vollständig belegt, dadurch war der Selector verdeckt und es gab kein `TO(0)`/`TG()`. Einmal aktiviert kam man nur per Neustart raus. Fix: `TO(0)` auf den linken Daumen (erste Daumentaste) gelegt.
- **`TO(1)` aus dem Selector entfernt** – Layer 1 (Navigation) ist ein Momentary-Layer (`LT(1,ENT)`) und hatte über `TO(1)` keinen Rückweg (Escape-Position = `KC_END`). `TO(1)` durch `KC_NO` ersetzt.

### Cleanup

- **Tap Dance komplett entfernt** – `TAP_DANCE_ENABLE`, alle 20 `TD_*`-Actions, `dance_open/close_bracket`, die Structs und Forward-Declarations waren toter Code (kein `TD()` wurde irgendwo benutzt). Spart Firmware-Größe.
- Ungenutztes `enum charybdis_keymap_layers` entfernt.

Kompiliert sauber (`qmk compile -kb bastardkb/charybdis/4x6/v2/splinky_3 -km smierx`), Overlayer-Tests grün.
