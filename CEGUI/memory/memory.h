#ifndef MEMORY_H
#define MEMORY_H
#include <unistd.h>
#include <assert.h>
#include <string>
#include <memory>
#include <initializer_list>

namespace CEGUI {
    namespace MEMORY {
        // TODO: define inside header in order to take advantage of compiler inline optimization
        // TODO: create move constructors for more efficient data manipulation (class(class&&) const)
        // TODO: figure out what to do with "The big 4" <--- get rid of them, that's what

        /*template<typename Memtype, size_t v_size>
        class StaticMem;

        template<typename Memtype, size_t v_size>
        class unique_static_ptr;

        template<typename Memtype>
        class unique_dynamic_ptr;

        template<typename Memtype, size_t v_size>
        class shared_static_ptr;

        template<typename Memtype>
        class shared_dynamic_ptr;

        // DECLERATIONS ^^^^^^

        template<typename Memtype>
        class DynamicMem { // dynamic memory can be resized, works best as a light container std::vector
        private:
            Memtype* m_block;
            size_t m_size;
        public:
            DynamicMem();
            DynamicMem(std::initializer_list<Memtype> l);
            ~DynamicMem();

            void push_back(const Memtype& elem);
            std::unique_ptr<Memtype> pop_back(int n);
            void del_element(int n);
            void insert_element(const Memtype& elm, int n);
            Memtype* release();

            const size_t size() const;

            const Memtype * const get_block() const {
                return m_block;
            }

            DynamicMem(const DynamicMem<Memtype>&);
            DynamicMem(DynamicMem<Memtype>&& mov);
            DynamicMem<Memtype>& operator=(const DynamicMem<Memtype>&);

            const Memtype& operator[](int n) const {
                if (n > (m_size - 1)) {}
                return *((*m_block)[n]);
            }

            friend class unique_dynamic_ptr;
            friend class shared_dynamic_ptr;
        };

        template<typename Memtype, size_t v_size> // size is for explicitly defining types, ex typedef CEdynamic<CEbyte, 100> block;
        class StaticMem { // static memory cannot be resized
        private:
            Memtype* m_block;
            size_t m_size = v_size;
        public:
            StaticMem();
            StaticMem(Memtype* block);
            StaticMem(std::initializer_list<Memtype> l);
            ~StaticMem() {delete m_block;}

            StaticMem(const StaticMem<Memtype, m_size>&);
            StaticMem(const StaticMem<Memtype, v_size>&& mov);
            StaticMem<Memtype, size_t>& operator=(const StaticMem<Memtype, size>&);

            const Memtype const* get_block() const {
                return m_block;
            }

            const Memtype& operator*() const {
                return *m_block;
            }
            
            const Memtype& operator[](int n) const {
                if (n > (m_size-1)) {}
                return m_block[n];
            }

            friend class unique_static_ptr;
            friend class shared_static_ptr;
        };

        template<typename Memtype, size_t v_size>
        class unique_static_ptr {
        private:
            std::unique_ptr<StaticMem<Memtype, v_size>> m_ptr;
        public:
            unique_static_ptr(std::initializer_list<Memtype*> l);
            ~unique_static_ptr();

            typedef Memtype Mtype;

            unique_static_ptr(const unique_static_ptr<Memtype, v_size>&) = delete;
            unique_static_ptr(unique_static_ptr<Memtype, v_size>&& mov);
            unique_static_ptr<Memtype, v_size>& operator=(unique_static_ptr<MemType, v_size>&);

            const size_t size() const {
                return v_size;
            }

            const Memtype& operator[](int n) const {
                return (*m_ptr)[n];
            }

            Memtype& operator[](int n) {
                return (*m_ptr)[n];
            }
        };

        template<typename Memtype>
        class unique_dynamic_ptr {
        private:
            std::unique_ptr<DynamicMem<Memtype>> m_ptr;
        public:
            unique_dynamic_ptr(std::initializer_list<Memtype*> l);
            ~unique_dynamic_ptr();

            typedef Memtype Mtype;

            unique_dynamic_ptr(const unique_dynamic_ptr<Memtype>&) = delete;
            unique_dynamic_ptr(unique_dynamic_ptr<Memtype>&& mov);
            unique_dynamic_ptr<Memtype>& operator=(unique_dynamic_ptr<Memtype>&);

            const size_t size() const {
                return (*m_ptr).get_length();
            }

            const Memtype& operator[](int n) const {
                return (*m_ptr)[n];
            }

            Memtype& operator[](int n) {
                return (*m_ptr)[n];
            }

            const DynamicMem<Memtype>& operator->() const {
                return *m_ptr
            }

        };

        template<typename Memtype, size_t v_size> 
        class shared_static_ptr {
        private:
            std::shared_ptr<StaticMem<Memtype, v_size>> m_ptr;
        public:
            shared_static_ptr(std::initializer_list<Memtype*> l);
            ~shared_static_ptr();

            typedef Memtype Mtype;

            shared_static_ptr(const shared_static_ptr<Memtype, v_size>&);
            shared_static_ptr(shared_static_ptr<Memtype, v_size>&& mov);
            shared_static_ptr<Memtype, v_size>& operator=(shared_static_ptr<Memtype, v_size>&);

            const size_t size() const {
                return v_size;
            }

            const Memtype& operator[](int n) const {
                return (*m_ptr)[n];
            }

            Memtype& operator[](int n) {
                return (*m_ptr)[n];
            }
        };

        template<typename Memtype>
        class shared_dynamic_ptr {
        private:
            std::shared_ptr<DynamicMem<Memtype>> m_ptr;
        public:
            shared_dynamic_ptr(std::initializer_list<Memtype> l);
            ~shared_dynamic_ptr();

            typedef Memtype Mtype;

            shared_dynamic_ptr(const shared_dynamic_ptr<Memtype>&);
            shared_dynamic_ptr(shared_dynamic_ptr<Memtype>&& mov);
            shared_dynamic_ptr<Memtype>& operator=(shared_dynamic_ptr<Memtype>&);

            const size_t size() const {
                return (*m_ptr).get_length();
            }

            const Memtype& operator[](int n) const {
                return (*m_ptr)[n];
            }

            Memtype& operator[](int n) {
                return (*m_ptr)[n];
            }

            const DynamicMem<Memtype>& operator->() const {
                return *m_ptr;
            }
        };*/

        class Unknown { // !NOT SHARED MEMORY SAFE!
        private:
            void* m_ptr;
            size_t m_size;
        public:
            Unknown(void* ptr, size_t size);
            ~Unknown();
            const Unknown& operator=(const Unknown&) const;
            Unknown(const Unknown&);
            Unknown(Unknown&& u);

            void* get() const {return m_ptr;}
            const size_t size() const {return m_size;}
        };

        class ByteArray {
        private:
            u_char* arr;
            size_t size;
        public:
            
        };

        /*template<typename P, typename C>
        class PClink { // programmer-chair link, the chair cant be destroyed until the programmer says so, but if the programmer is destroyed, other programmers can use the chair
        private:
            //StaticMem<P> m_pr;
            //StaticMem<C> m_cha;
        public:
            PClink(P* pr, C* cha);
            ~PClink();
            
            typedef P Ptype;
            typedef C Ctype;

            C* breaklink(); // deletes the programmer and returns the chair


            const P* getpr() const;
            const C* getcha() const;

        };


        template<typename First, typename Second>
        class SDLink { // Static dependant link (each element cannot exist without the other, and the memory cannot be resized)
        private:
            //StaicMem<First> m_f;
            //StaticMem<Second> m_s;
        public:
            DLink(First* f, Second* s);
            ~DLink();

            typedef First Ftype;
            typedef Second Stype;




        };

        template<typename First, typename Second>
        class DDLink { // Dynamic dependant link same as SDLink exept the memory can be resized
        private:


        public:


        };*/
    };
};

#endif
