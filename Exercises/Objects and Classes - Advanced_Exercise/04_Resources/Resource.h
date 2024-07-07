//
// Created by User on Сб-6.7.2024 г..
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

using SoftUni::ResourceType;




namespace SoftUni{
    class Resource{
        friend std::istream& operator>>(std::istream&, Resource&);
        friend std::ostream& operator<<(std::ostream&, const Resource&);

    private:
        int m_ID;
        ResourceType m_RT;
        std::string m_LINK;


    public:
        Resource(int id =0, ResourceType rt =PRESENTATION, std::string link ="") :
        m_ID(id),
        m_RT(rt),
        m_LINK(std::move(link)){}

//      getters
        int getId() const { return m_ID; }
        ResourceType getType() const { return m_RT; }
        std::string getLink() const { return m_LINK; }

//      setters
        void setID(int id) { m_ID = id; }
        void setRT(ResourceType rt) { m_RT = rt; }
        void setLink(std::string lnk) { m_LINK = lnk; }

    };

    std::istream& operator>>(std::istream& IN, Resource& obj){
        int tempID;
        ResourceType tempRT;
        std::string tempLink;

        IN >> tempID;
        obj.setID(tempID);

        unsigned int trt = 0;
        if(IN >> trt){
            tempRT = static_cast<ResourceType>(trt);
            obj.setRT(tempRT);
        }

        IN >> tempLink;
        obj.setLink(tempLink);

        return IN;
    }

    std::ostream& operator<<(std::ostream& OUT, const Resource& obj){
        OUT << obj.getType() << " " << (unsigned)obj.getType() << obj.m_LINK;
        return OUT;
    }


}
//TODO overload .inset method from std::set

using SoftUni::Resource;
using std::pair;
using std::set;
using std::iterator;
typedef set<Resource>::iterator IT;

template <>
pair<IT, bool> set<Resource>::insert(Resource &&x) {

}




#endif //!RESOURCE_H
