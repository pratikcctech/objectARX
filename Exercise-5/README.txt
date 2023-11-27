1) The makeLayer function is designed to create a new layer named "OBJ" within the current AutoCAD drawing upon execution,

2) if such a layer does not already exist. 
3) The code first checks the Layer Table for the presence of a layer named "OBJ." 

4) If the layer is not found, the function proceeds to:
    1.Open the Layer Table for write access.
    2.Create a new AcDbLayerTableRecord representing the "OBJ" layer.
    3.Set the layer's name to "OBJ" and its color to cyan.
    4.Add the new layer to the Layer Table.
    5.Close both the Layer Table and the created layer record to release resources.
  
5) The makeLayer function ensures the existence of a "OBJ" layer in the drawing and creates it with specified properties if needed.
