# Unit Converter Application

## Overview

The Unit Converter App provides a simple and efficient way to convert between various measurement units across categories like temperature, distance, area, volume, and mass.

## Usage

convert [-t char] [-iv double] [-iu unit] [-o unit] [...options]

## Options

**`-t TYPE`**

Specify the type of conversion. This is a required field.
The following are the correct values for the type option:

- `t` or `T`: Temperature
- `d` or `D`: Distance
- `a` or `A`: Area
- `v` or `V`: Volume
- `m` or `M`: Mass

- **`-iv <number><unit>`**  
  Specify the input value for the conversion. This input is optional, and if not provided, it will instead run a loop to continuously convert the numbers provided in stdin
  Example: `100`, `500`, `1`.

- **`-iu <unit>`**  
  Specify the input unit to convert from. This is a required field.  
  Example: `m`, `mi`, `kg`.

- **`-o <unit>`**  
  Specify the target unit for the conversion. This is a required field.
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
