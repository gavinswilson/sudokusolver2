def set_value(self, x,y,val):
    self.grid[x-1][y-1]=val

def set_opts(self,x,y,val):
    self.opts[x-1][y-1]=val

def set_region(self,x,y,region):
    self.regions[x-1][y-1]=region

#99 is the 'empty' cell number
def clear_grid(self, num):
    for i in range(1, self.rows+1):
        for j in range(1, self.cols+1):
            #self.grid[i][j]=num
            self.set_value(i,j,num)

def set_all_opts(self):
    for i in range(1, self.rows+1):
        for j in range(1, self.cols+1):
            #self.opts[i][j]=self.all_options_number_bin()
            self.set_opts(i,j, self.all_options_number_bin())

def set_region_map(self, map=None):
    if map == None:
        map = [1,1,1,2,2,2,3,3,3,1,1,1,2,2,2,3,3,3,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,4,4,4,5,5,5,6,6,6,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,7,7,7,8,8,8,9,9,9,7,7,7,8,8,8,9,9,9]
        self.region_map = map[:]
    else:
        pass
        #check for a valid passed region and set it!
        self.region_map = map[:]

def set_regions(self):    
    index = 0
    for i in range(1, self.rows+1):
        for j in range(1, self.cols+1):
            self.set_region(i,j,self.region_map[index])
            index=index+1

