/**
 * Autogenerated by Thrift Compiler (1.0.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Serv_H
#define Serv_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "student_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ServIf {
 public:
  virtual ~ServIf() {}
  virtual void put(const Student& s) = 0;
  virtual void get(Student& _return, const int32_t sno) = 0;
};

class ServIfFactory {
 public:
  typedef ServIf Handler;

  virtual ~ServIfFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServIf* /* handler */) = 0;
};

class ServIfSingletonFactory : virtual public ServIfFactory {
 public:
  ServIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<ServIf>& iface) : iface_(iface) {}
  virtual ~ServIfSingletonFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ServIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<ServIf> iface_;
};

class ServNull : virtual public ServIf {
 public:
  virtual ~ServNull() {}
  void put(const Student& /* s */) {
    return;
  }
  void get(Student& /* _return */, const int32_t /* sno */) {
    return;
  }
};

typedef struct _Serv_put_args__isset {
  _Serv_put_args__isset() : s(false) {}
  bool s :1;
} _Serv_put_args__isset;

class Serv_put_args {
 public:

  Serv_put_args(const Serv_put_args&);
  Serv_put_args& operator=(const Serv_put_args&);
  Serv_put_args() {
  }

  virtual ~Serv_put_args() throw();
  Student s;

  _Serv_put_args__isset __isset;

  void __set_s(const Student& val);

  bool operator == (const Serv_put_args & rhs) const
  {
    if (!(s == rhs.s))
      return false;
    return true;
  }
  bool operator != (const Serv_put_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_put_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_put_pargs {
 public:


  virtual ~Serv_put_pargs() throw();
  const Student* s;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_put_result {
 public:

  Serv_put_result(const Serv_put_result&);
  Serv_put_result& operator=(const Serv_put_result&);
  Serv_put_result() {
  }

  virtual ~Serv_put_result() throw();

  bool operator == (const Serv_put_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Serv_put_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_put_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_put_presult {
 public:


  virtual ~Serv_put_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Serv_get_args__isset {
  _Serv_get_args__isset() : sno(false) {}
  bool sno :1;
} _Serv_get_args__isset;

class Serv_get_args {
 public:

  Serv_get_args(const Serv_get_args&);
  Serv_get_args& operator=(const Serv_get_args&);
  Serv_get_args() : sno(0) {
  }

  virtual ~Serv_get_args() throw();
  int32_t sno;

  _Serv_get_args__isset __isset;

  void __set_sno(const int32_t val);

  bool operator == (const Serv_get_args & rhs) const
  {
    if (!(sno == rhs.sno))
      return false;
    return true;
  }
  bool operator != (const Serv_get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_get_pargs {
 public:


  virtual ~Serv_get_pargs() throw();
  const int32_t* sno;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_get_result__isset {
  _Serv_get_result__isset() : success(false) {}
  bool success :1;
} _Serv_get_result__isset;

class Serv_get_result {
 public:

  Serv_get_result(const Serv_get_result&);
  Serv_get_result& operator=(const Serv_get_result&);
  Serv_get_result() {
  }

  virtual ~Serv_get_result() throw();
  Student success;

  _Serv_get_result__isset __isset;

  void __set_success(const Student& val);

  bool operator == (const Serv_get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Serv_get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_get_presult__isset {
  _Serv_get_presult__isset() : success(false) {}
  bool success :1;
} _Serv_get_presult__isset;

class Serv_get_presult {
 public:


  virtual ~Serv_get_presult() throw();
  Student* success;

  _Serv_get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServClient : virtual public ServIf {
 public:
  ServClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ServClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void put(const Student& s);
  void send_put(const Student& s);
  void recv_put();
  void get(Student& _return, const int32_t sno);
  void send_get(const int32_t sno);
  void recv_get(Student& _return);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<ServIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ServProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServProcessor(::apache::thrift::stdcxx::shared_ptr<ServIf> iface) :
    iface_(iface) {
    processMap_["put"] = &ServProcessor::process_put;
    processMap_["get"] = &ServProcessor::process_get;
  }

  virtual ~ServProcessor() {}
};

class ServProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< ServIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< ServIfFactory > handlerFactory_;
};

class ServMultiface : virtual public ServIf {
 public:
  ServMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<ServIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<ServIf> > ifaces_;
  ServMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<ServIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void put(const Student& s) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->put(s);
    }
    ifaces_[i]->put(s);
  }

  void get(Student& _return, const int32_t sno) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get(_return, sno);
    }
    ifaces_[i]->get(_return, sno);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ServConcurrentClient : virtual public ServIf {
 public:
  ServConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ServConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void put(const Student& s);
  int32_t send_put(const Student& s);
  void recv_put(const int32_t seqid);
  void get(Student& _return, const int32_t sno);
  int32_t send_get(const int32_t sno);
  void recv_get(Student& _return, const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif
