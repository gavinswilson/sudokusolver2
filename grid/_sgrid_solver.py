import numpy as np


def remove_knowns(self):
    for i in range(1, self.rows+1):
        for j in range(1, self.cols+1):
            # loop through all cells, indexes start at zero....
            if self.get_value(i, j)==self.null_value:
                pass
                #do nothing if the value isnt set
            else:
                clean_value = self.get_value(i, j)
                clean_region = self.get_region(i, j)
                clean_row = i
                clean_column = j
                for x in range(1, self.rows+1):
                    for y in range(1, self.cols+1):
                        print("x:", x, " y:", y,"i:", "reg:", self.get_region(x,y), i, " j:", j, " Clean Val:", clean_value, " clean_region:", clean_region)
                        if (x==clean_row) or (y==clean_column) or (self.get_region(x,y)==clean_region):
                            self.remove_knows_from_cell_opts(x,y,clean_value)

                                    
def remove_knows_from_cell_opts(self, x,y, value):
    lmask=self.mask
    opts=np.uint16(self.get_opts(x,y))+lmask
    lmask=lmask+np.uint16(value)
    opts=np.invert(np.bitwise_and(opts,lmask))
    self.set_opts(x,y,opts)    

