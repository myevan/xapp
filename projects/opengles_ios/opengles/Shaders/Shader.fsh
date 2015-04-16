//
//  Shader.fsh
//  opengles
//
//  Created by Song Young-jin on 2015. 4. 17..
//  Copyright (c) 2015년 com.example. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
