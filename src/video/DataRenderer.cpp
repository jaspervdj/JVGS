#include "DataRenderer.h"

using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace video
    {
        DataRenderer::DataRenderer()
        {
        }

        DataRenderer::~DataRenderer()
        {
        }

        void DataRenderer::vector(const Vector2D &vector)
        {
            data.push_back(vector);
        }

        vector<Vector2D> *DataRenderer::getData()
        {
            return &data;
        }
    }
}
