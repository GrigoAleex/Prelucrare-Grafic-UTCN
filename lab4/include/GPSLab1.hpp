//
//  GPSLab1.hpp
//
//  Copyright © 2017 CGIS. All rights reserved.
//

#ifndef GPSLab1_hpp
#define GPSLab1_hpp

#include <stdio.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace gps {
    glm::vec4 TransformPoint(const glm::vec4 &point);

    float ComputeAngle(const glm::vec3 &v1, const glm::vec3 &v2);

    bool IsConvex(const std::vector<glm::vec2> &vertices);

    std::vector<glm::vec2> ComputeNormals(const std::vector<glm::vec2> &vertices);
}

#endif /* GPSLab1_hpp */
