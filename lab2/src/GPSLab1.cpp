//
//  Copyright © 2017 CGIS. All rights reserved.
//

#include "../include/GPSLab1.hpp"

namespace gps {
glm::vec4 TransformPoint(const glm::vec4 &point)
{
    glm::vec3 translation(2.0f, 0.0f, 1.0f);
    float angleInRadians = glm::radians(90.0f);
    
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angleInRadians, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), translation);

    return rotationMatrix * translationMatrix * point;
}

float ComputeAngle(const glm::vec3 &v1, const glm::vec3 &v2)
{
    float dotProduct = glm::dot(v1, v2);
    float magnitudeV1 = glm::length(v1);
    float magnitudeV2 = glm::length(v2);

    if (magnitudeV1 == 0.0f || magnitudeV2 == 0.0f) {
        return 0.0f;
    }

    float cosValue = dotProduct / (magnitudeV1 * magnitudeV2);
    float angleInRadians = acos(glm::clamp(cosValue, -1.0f, 1.0f));

    return glm::degrees(angleInRadians);
}

bool IsConvex(const std::vector<glm::vec2> &vertices)
{
    int n = vertices.size();
    if (n < 3) return false;

    bool isPositive = false;
    bool isNegative = false;

    for (int i = 0; i < n; ++i) {
        glm::vec2 current = vertices[i];
        glm::vec2 next = vertices[(i + 1) % n];
        glm::vec2 nextNext = vertices[(i + 2) % n];

        glm::vec2 edge1 = next - current;
        glm::vec2 edge2 = nextNext - next;

        float crossProduct = edge1.x * edge2.y - edge1.y * edge2.x;

        if (crossProduct < 0) {
            isNegative = true;
        } else if (crossProduct > 0) {
            isPositive = true;
        }

        if (isPositive && isNegative) return false;
    }

    return true;
}

std::vector<glm::vec2> ComputeNormals(const std::vector<glm::vec2> &vertices)
{
    std::vector<glm::vec2> normalsList;

    for (size_t i = 0; i < vertices.size(); ++i) {
        glm::vec2 current = vertices[i];
        glm::vec2 next = vertices[(i + 1) % vertices.size()];

        glm::vec2 edge = next - current;
        int getNormalX = edge.x != 0 ? -edge.x : 0; 
        glm::vec2 normal(edge.y, getNormalX);
        normal = glm::normalize(normal);

        normalsList.push_back(normal);
    }

    return normalsList;
}
}
