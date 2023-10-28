#returns number of rows
def get_rows(self):
        return self.rows
#returns number of columns
def get_cols(self):
        return self.cols
#returns number of columns
def get_opts_min(self):
        return self.options_min
#returns number of columns
def get_opts_max(self):
        return self.options_max
#returns number of columns
def get_mask(self):
        return self.mask
#returns a specific cell value
def get_value(self, x,y):
    return self.grid[x-1][y-1]
#returns a specific cell option set
def get_opts(self, x,y):
    return self.opts[x-1][y-1]

#returns a specific cell region 
def get_region(self, x,y):
    return self.regions[x-1][y-1]
