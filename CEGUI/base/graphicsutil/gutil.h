#ifndef GUTIL_H
#define GUTIL_H

#include <application/window.h>

namespace CEGUI {
    namespace RENDERING {
        // Top left of screen is (0,0)

        // Brasenhams line algorithm has many uses in the optimization of polygon drawing.
        // This structure stores the algorithms "position" and is incremented via a Brasenham function
        

        struct BresenhamAlgorithm {
            int dx,dy;
            int x,y;
            int e;

            void *incFunc(BresenhamAlgorithm* ba);
        };

        namespace BHAlgorithms {
            void ml1BHA(BresenhamAlgorithm* ba); // m < 1 and positive (ideal brasenham algorithm)
            void mg1BHA(BresenhamAlgorithm* ba); // m < 1 and negative (a little less ideal...)
            void nml1BHA(BresenhamAlgorithm* ba); // m > 1 and positive (ok just need to change a little...)
            void nmg1BHA(BresenhamAlgorithm* ba); // m > 1 and negative (strays most from the original formula :/ )
        };

        //BresenhamAlgorithm* GetBAlgorithm(); // remember to delete structure to prevent memory leaks

        void drawline(const CEGUI::APP::Framebuffer& framebuff, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

        void drawRect(const CEGUI::APP::Framebuffer& framebuff, unsigned int x, unsigned int y, unsigned int width, unsigned int height); // x,y from top left corner

        void drawIRect(const CEGUI::APP::Framebuffer& framebuff, unsigned int x1, unsigned int x2, unsigned int y[]);
        /* y array (size of 4):
            4-----------------3
            |                 |
            |                 |
            1-----------------2
        */

    };
};

#endif
