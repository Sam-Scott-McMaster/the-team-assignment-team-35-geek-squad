# Unit Converter Application

## Overview
The Unit Converter App provides a simple and efficient way to convert between various measurement units across categories like temperature, distance, area, volume, and mass.

## Usage
convert [-t t|T|d|D|a|A|v|V|m|M] [-i <number><unit>] [-o <unit>] [...options]

## Options

  **`-t TYPE`** 
  
  Specify the type of conversion:
  - `t` or `T`: Temperature
  - `d` or `D`: Distance
  - `a` or `A`: Area
  - `v` or `V`: Volume
  - `m` or `M`: Mass

- **`-i <number><unit>`**  
  Specify the input value and unit to convert from.  
  Example: `100km`, `500yd`, `1L`.

- **`-o <unit>`**  
  Specify the target unit for the conversion.  
  Example: `m`, `mi`, `kg`.

- **`-ru`**  
  Remove the unit from the output.  
  Example: Converts `1000m` to `1km` as `1` instead of `1km`.

## Supported Conversions

1. **Temperature**  
   - Kelvin, Celsius, Fahrenheit

2. **Distance**  
   - **Metric**: Terameter, Gigameter, ..., Meter, ..., Millimeter  
   - **Imperial**: Inch, Foot, Yard, Mile

3. **Area**  
   - **Metric**: Terameter², ..., Millimeter²  
   - **Imperial**: Inch², Foot², Yard², Mile²

4. **Volume**  
   - **Metric**: Terameter³, ..., Millimeter³  
   - **Imperial**: Inch³, Foot³, Yard³, Mile³

5. **Mass**  
   - **Metric**: Teragram, ..., Milligram  
   - **Imperial**: Ounce, Pound, Stone

## Notes
- Use appropriate units for input and output to ensure accurate results.
- The app will notify you of invalid inputs or unsupported conversions. 

For further help, refer to the **help menu** by consulting the source code.
