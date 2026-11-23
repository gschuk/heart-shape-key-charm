# Heart-shape-key-charm
This project features a key charm to display simple animations using 7 SMD LEDs. The key charm is meant to be used without a case and includes a hole thoughout the PCB to connect it to a keychain.

<div>
    <div style="display:inline-block; text-align:center;">
        <img src="figures/FrontsidePCB.png" width=350 height=350><br>
        <em> Front view </em>
    </div><div style="display:inline-block; text-align:center;">
        <img src="figures/BacksidePCB.png" width=350 height=350><br>
        <em> Back view </em>
    </div>
</div>

## Specification:
Microcontroller: **Attiny 84a** <br>
Powersource: **CR 2032** <br>
LEDs: **Kingsbright red (2mA)** <br>
Power Switch: **Slide Switch (EG1215AA)**<br>

## Documentation:
Software: **firmware/README.md** <br>
Hardware: **hardware/README.md** <br>

## Assembly / Soldering:
The keycharm was designed to hold most of its SMD components on the front side of the pcb. For this reason the keycharm can easily be soldered at home. The fastest way is using a stencil (order with pcb) and a heatplate.
### Setup:
#### Heatplate
The **UYUE 946C** heatplate was used for this setup. It was heat up to **230 °C** and a pcb was "baked" for approximately **2 min and 30 seconds** (check datasheet of your components no guarantee that it will work, something could always brake). 
#### Solderpaste
KEK Solder Paste with the following specification was used: <br>
Sn-96.5 Ag-3.0 Cu-0.5 (microns:20-38) melting point at approximately 217 °C