#ifndef CAFFE_CONV_LAYER_HPP_
#define CAFFE_CONV_LAYER_HPP_

#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/filler.hpp"

namespace caffe {

template <typename Dtype>
class ConvolutionLayer : public Layer<Dtype> 
{
 public:
  explicit ConvolutionLayer(const LayerParameter& param): Layer<Dtype>(param) {}
	virtual ~ConvolutionLayer();
  virtual inline const char* type() const { return "Convolution"; }
  
	virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top);

  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top);



  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top, const vector<Blob<Dtype>*>& bottom);
  virtual void SecForward_gpu(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top);    
      
 protected:
  
	int num_output_;
  int channels_;
  int kernel_size_;
  int pad_;
  int stride_;
  int filter_stride_;
  int group_;
  
  int kernel_eff_;
	int height_out_;
	int width_out_;

	
//------------------------------------------	
	Blob<Dtype> * col_buffer_;
	Blob<Dtype> * bias_multiplier_;
	int gpu_id_;	
//------------------------------------------
};

}  // namespace caffe

#endif  // CAFFE_CONV_LAYER_HPP_
